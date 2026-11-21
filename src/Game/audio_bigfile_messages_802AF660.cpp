/* Fixed-width diagnostics retained with the original audio bigfile storage. */
struct AudioBigfileMessages {
    char initialized[28];
    char nullName[16];
    char alreadyEnabled[20];
};

extern "C" const AudioBigfileMessages lbl_802AF660 = {
    "Sound bigfile initialized!!",
    "BFName is NULL!",
    "BF already enabled!"
};
