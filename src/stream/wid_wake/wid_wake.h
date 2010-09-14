/*
* WiderWake
* (C) 1999-2008 Jack Lloyd
*
* Distributed under the terms of the Botan license
*/

#ifndef BOTAN_WIDER_WAKE_H__
#define BOTAN_WIDER_WAKE_H__

#include <botan/stream_cipher.h>

namespace Botan {

/**
* WiderWake4+1-BE
*
* Note: quite old and possibly not safe; use XSalsa20 or a block
* cipher in counter mode.
*/
class BOTAN_DLL WiderWake_41_BE : public StreamCipher
   {
   public:
      void cipher(const byte[], byte[], u32bit);
      void set_iv(const byte[], u32bit);

      bool valid_iv_length(u32bit iv_len) const
         { return (iv_len == 8); }

      void clear();
      std::string name() const { return "WiderWake4+1-BE"; }
      StreamCipher* clone() const { return new WiderWake_41_BE; }

      WiderWake_41_BE() : StreamCipher(16, 16, 1),
                          T(256), state(5), t_key(4),
                          buffer(DEFAULT_BUFFERSIZE), position(0)
         { }

   private:
      void key_schedule(const byte[], u32bit);

      void generate(u32bit);

      SecureVector<u32bit> T;
      SecureVector<u32bit> state;
      SecureVector<u32bit> t_key;
      SecureVector<byte> buffer;
      u32bit position;
   };

}

#endif
