/* Worker request words cleared by cancellation and set by request submission. */
unsigned long lbl_8037809C;
unsigned long lbl_80378098;

typedef char WorkerRequestWordSizeCheck[sizeof(unsigned long) == 4 ? 1 : -1];
