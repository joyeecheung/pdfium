// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_overflow.h"

#include "fxjs/xfa/cjx_node.h"
#include "third_party/base/ptr_util.h"

namespace {

const CXFA_Node::AttributeData kOverflowAttributeData[] = {
    {XFA_Attribute::Id, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Use, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Trailer, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Usehref, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Target, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Leader, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Unknown, XFA_AttributeType::Integer, nullptr}};

}  // namespace

CXFA_Overflow::CXFA_Overflow(CXFA_Document* doc, XFA_PacketType packet)
    : CXFA_Node(doc,
                packet,
                (XFA_XDPPACKET_Template | XFA_XDPPACKET_Form),
                XFA_ObjectType::Node,
                XFA_Element::Overflow,
                nullptr,
                kOverflowAttributeData,
                pdfium::MakeUnique<CJX_Node>(this)) {}

CXFA_Overflow::~CXFA_Overflow() = default;
