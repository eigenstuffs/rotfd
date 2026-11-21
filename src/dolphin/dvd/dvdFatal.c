/* Dolphin DVD fatal-message callback, GSQE78. Public Pikmin 2 SDK adaptation. */
static void (*FatalFunc)();

void __DVDPrintFatalMessage(void)
{
	if (FatalFunc != 0) {
		(*FatalFunc)();
	}
	return;
}
