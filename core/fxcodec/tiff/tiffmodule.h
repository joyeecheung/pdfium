// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef CORE_FXCODEC_TIFF_TIFFMODULE_H_
#define CORE_FXCODEC_TIFF_TIFFMODULE_H_

#include <memory>

#include "core/fxcodec/progressive_decoder_iface.h"

#ifndef PDF_ENABLE_XFA_TIFF
#error "TIFF must be enabled"
#endif

class CFX_DIBitmap;
class IFX_SeekableReadStream;

namespace fxcodec {

class CFX_DIBAttribute;

class TiffModule {
 public:
  static std::unique_ptr<ProgressiveDecoderIface::Context> CreateDecoder(
      const RetainPtr<IFX_SeekableReadStream>& file_ptr);

  static bool LoadFrameInfo(ProgressiveDecoderIface::Context* ctx,
                            int32_t frame,
                            int32_t* width,
                            int32_t* height,
                            int32_t* comps,
                            int32_t* bpc,
                            CFX_DIBAttribute* pAttribute);
  static bool Decode(ProgressiveDecoderIface::Context* ctx,
                     const RetainPtr<CFX_DIBitmap>& pDIBitmap);

  TiffModule() = delete;
  TiffModule(const TiffModule&) = delete;
  TiffModule& operator=(const TiffModule&) = delete;
};

}  // namespace fxcodec

using TiffModule = fxcodec::TiffModule;

#endif  // CORE_FXCODEC_TIFF_TIFFMODULE_H_
