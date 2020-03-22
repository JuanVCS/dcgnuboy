/* KallistiOS ##version##

   mouse.c
   (C)2002 Dan Potter
*/

#include <dc/maple.h>
#include <dc/maple/mouse.h>
#include <string.h>

CVSID("mouse.c,v 1.1 2002/02/22 07:34:20 bardtx Exp");

static void mouse_reply(maple_frame_t *frm) {
	maple_response_t	*resp;
	uint32			*respbuf;

	/* Unlock the frame now (it's ok, we're in an IRQ) */
	maple_frame_unlock(frm);

	/* Make sure we got a valid response */
	resp = (maple_response_t *)frm->recv_buf;
	if (resp->response != MAPLE_RESPONSE_DATATRF)
		return;
	respbuf = (uint32 *)resp->data;
	if (respbuf[0] != MAPLE_FUNC_MOUSE)
		return;

	/* Update the status area from the response */
	if (frm->dev) {
		memcpy(frm->dev->status, respbuf+1, (resp->data_len-1) * 4);
		frm->dev->status_valid = 1;
	}
}

static int mouse_poll(maple_device_t *dev) {
	uint32 * send_buf;

	if (maple_frame_lock(&dev->frame) < 0)
		return 0;

	maple_frame_init(&dev->frame);
	send_buf = (uint32 *)dev->frame.recv_buf;
	send_buf[0] = MAPLE_FUNC_MOUSE;
	dev->frame.cmd = MAPLE_COMMAND_GETCOND;
	dev->frame.dst_port = dev->port;
	dev->frame.dst_unit = dev->unit;
	dev->frame.length = 1;
	dev->frame.callback = mouse_reply;
	dev->frame.send_buf = send_buf;
	maple_queue_frame(&dev->frame);

	return 0;
}

static void mouse_periodic(maple_driver_t *drv) {
	maple_driver_foreach(drv, mouse_poll);
}

static int mouse_attach(maple_driver_t *drv, maple_device_t *dev) {
	memset(dev->status, 0, sizeof(dev->status));
	dev->status_valid = 0;
	return 0;
}

static void mouse_detach(maple_driver_t *drv, maple_device_t *dev) {
	dev->status_valid = 0;
}

/* Device Driver Struct */
static maple_driver_t mouse_drv = {
	functions:	MAPLE_FUNC_MOUSE,
	name:		"Mouse Driver",
	periodic:	mouse_periodic,
	attach:		mouse_attach,
	detach:		mouse_detach
};

/* Add the mouse to the driver chain */
int mouse_init() {
	return maple_driver_reg(&mouse_drv);
}

void mouse_shutdown() {
	maple_driver_unreg(&mouse_drv);
}

