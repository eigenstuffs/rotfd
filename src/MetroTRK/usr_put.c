/* MetroTRK debug output. See docs/notes/MetroTRK-usr_put.md. */
#include "trk_abi.h"
extern void SetTRKConnected(u32);
extern u32 GetTRKConnected(void);
extern void OSReport(const char*);

bool usr_puts_serial(const char* msg)
{
	bool connect_ = false;
	char c;
	char buf[2];

	while (!connect_ && (c = *msg++) != '\0') {
		bool connect = GetTRKConnected();

		buf[0] = c;
		buf[1] = '\0';

		SetTRKConnected(false);
		OSReport(buf);

		SetTRKConnected(connect);
		connect_ = false;
	}
	return connect_;
}

void usr_put_initialize(void) {}
