/* Native texture payload record constructor; see docs/notes/game-texture-payload-stream.md. */
#include "Game/texture_payload_stream.h"

extern "C" const float lbl_8037A420[2];

TexturePayloadRecord::TexturePayloadRecord()
{
    value = lbl_8037A420[0];
}
