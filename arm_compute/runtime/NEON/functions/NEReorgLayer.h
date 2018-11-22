/*
 * Copyright (c) 2018 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __ARM_COMPUTE_NEREORGLAYER_H__
#define __ARM_COMPUTE_NEREORGLAYER_H__

#include "arm_compute/core/Types.h"
#include "arm_compute/runtime/NEON/INESimpleFunction.h"

namespace arm_compute
{
// Forward declarations
class ITensor;

/** Basic function to run @ref NEReorgLayerKernel */
class NEReorgLayer : public INESimpleFunction
{
public:
    /** Initialise the kernel's inputs and outputs
     *
     * @param[in]  input  First tensor input. Data type supported: U8/S8/QASYMM8//U16/S16/U32/S32/F16/F32
     * @param[out] output Output tensor. Data type supported: Same as @p input
     * @param[in]  stride Stride to be used during data re-organization
     *                    It defines the spatial distance between 2 consecutive pixels in the x and y direction
     */
    void configure(const ITensor *input, ITensor *output, int32_t stride);

    /** Static function to check if given info will lead to a valid configuration of @ref NEReorgLayer
     *
     * @param[in] input  First tensor info. Data type supported: U8/S8/QASYMM8//U16/S16/U32/S32/F16/F32
     * @param[in] output Output tensor info. Data type supported: Same as @p input
     * @param[in] stride Stride to be used during data re-organization
     *                   It defines the spatial distance between 2 consecutive pixels in the x and y direction
     *
     * @return a status
     */
    static Status validate(const ITensorInfo *input, const ITensorInfo *output, int32_t stride);
};
} // namespace arm_compute
#endif /*__ARM_COMPUTE_NEREORGLAYER_H__ */
