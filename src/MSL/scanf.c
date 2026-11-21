/* Retained scan callback adapted from doldecomp/sms, commit
 * c44637d42e09ec81973c4579e13ece8d0b0f5f58.
 * License: reference/sms-msl/LICENSE.
 * Original text: 0x80127C8C..0x80127D1C.
 */
typedef struct { char *NextChar; int NullCharDetected; } __InStrCtrl;
enum { __GetAChar, __UngetAChar, __TestForError };

int __StringRead(void* pPtr, int ch, int act)
{
	int ret;
	__InStrCtrl* Iscp = (__InStrCtrl*)pPtr;

	switch (act) {
	case __GetAChar:
		ret = *(unsigned char *)(Iscp->NextChar);

		if ((signed char)ret == '\0') {
			Iscp->NullCharDetected = 1;
			return -1;
		} else {
			Iscp->NextChar++;
			return ret;
		}

	case __UngetAChar:
		if (Iscp->NullCharDetected == 0) {
			Iscp->NextChar--;
		} else {
			Iscp->NullCharDetected = 0;
		}

		return ch;

	case __TestForError:
		return Iscp->NullCharDetected;
	}

	return 0;
}
