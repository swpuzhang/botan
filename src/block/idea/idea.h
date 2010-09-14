/*
* IDEA
* (C) 1999-2007 Jack Lloyd
*
* Distributed under the terms of the Botan license
*/

#ifndef BOTAN_IDEA_H__
#define BOTAN_IDEA_H__

#include <botan/block_cipher.h>

namespace Botan {

/**
* IDEA
*/
class BOTAN_DLL IDEA : public BlockCipher
   {
   public:
      void encrypt_n(const byte in[], byte out[], u32bit blocks) const;
      void decrypt_n(const byte in[], byte out[], u32bit blocks) const;

      void clear() { zeroise(EK); zeroise(DK); }
      std::string name() const { return "IDEA"; }
      BlockCipher* clone() const { return new IDEA; }

      IDEA() : BlockCipher(8, 16), EK(52), DK(52) {}
   protected:
      /**
      * @return const reference to encryption subkeys
      */
      const SecureVector<u16bit>& get_EK() const { return EK; }

      /**
      * @return const reference to decryption subkeys
      */
      const SecureVector<u16bit>& get_DK() const { return DK; }

   private:
      void key_schedule(const byte[], u32bit);
      SecureVector<u16bit> EK, DK;
   };

}

#endif
