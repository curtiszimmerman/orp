/** @file aes.h
 *
   Copyright 2015, Google Inc.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */

#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>

/** @defgroup crypto Cryptographic services
 *  @{
 */

/** @defgroup aes AES
 *  @{
 */


/** @brief Algorithm selector. See `AES_128`, `AES_192`, and `AES_256`. */
typedef uint32_t aes_algo_t;

/** @brief AES 128 algorithm. */
#define AES_128   ((aes_algo_t) 0)

/** @brief AES 192 algorithm. */
#define AES_192   ((aes_algo_t) 1)

/** @brief AES 256 algorithm. */
#define AES_256   ((aes_algo_t) 2)

/** @brief Boolean run-time test to see if a given algo is valid. */
#define AES_IS_ALGO(x) (AES_128 == (x) || AES_196 == (x) || AES_256 == (x))

/** @brief Size (in bytes) of an AES block. */
#define AES_BLOCK_SIZE	16

/** @brief AES context object. */
typedef struct aes_ctx_s {
	aes_algo_t algo;
	uint32_t ks[60];
} aes_ctx_t;

/** @brief Size (in bytes) of an AES-128 key. */
#define AES_128_KEY_SIZE (128 / 8)

/** @brief Size (in bytes) of an AES-192 key. */
#define AES_192_KEY_SIZE (192 / 8)

/** @brief Size (in bytes) of an AES-256 key. */
#define AES_256_KEY_SIZE (256 / 8)

/** @brief Given a valid algo, yields the appropriate key size. */
#define AES_ALGO_KEY_SIZE(x) ( (AES_128 == (x)) ? AES_128_KEY_SIZE : AES_196 == (x)) ? AES_196_KEY_SIZE : AES_256_KEY_SIZE )

/** @brief The AES sbox. */
uint8_t aes_sbox(uint8_t U, int inv);

/** @brief Sets the key in the given context. */
void aes_setkey(aes_ctx_t *ctx, aes_algo_t algo, void *key);

/** @brief Performs encryption (electronic codebook mode) of the given data in the given context. */
void aes_ecb_encrypt(aes_ctx_t *ctx, void *data_in, void *data_out);

/** @brief Performs decryption (electronic codebook mode) of the given data in the given context. */
void aes_ecb_decrypt(aes_ctx_t *ctx, void *data_in, void *data_out);

/** @} */

/** @} */

#endif /* _AES_H_ */
