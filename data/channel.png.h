#ifndef CHANNEL_PNG_H
#define CHANNEL_PNG_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

static const unsigned char channel_png[] =
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x40, 
	0x00, 0x00, 0x00, 0x40, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 
	0x60, 0xB9, 0x55, 0x00, 0x00, 0x06, 0x74, 0x49, 0x44, 0x41, 
	0x54, 0x68, 0xDE, 0xED, 0x59, 0x79, 0x88, 0x55, 0x55, 0x18, 
	0xFF, 0xDD, 0x7B, 0x9F, 0xB9, 0x94, 0x0E, 0x39, 0x62, 0x51, 
	0x92, 0x19, 0x93, 0x51, 0x68, 0x86, 0x48, 0x28, 0x2D, 0x44, 
	0x99, 0x26, 0x53, 0x1A, 0x48, 0xD2, 0x42, 0xD4, 0x44, 0x13, 
	0x2D, 0xFF, 0x09, 0x4D, 0x53, 0x19, 0x61, 0x46, 0xA1, 0x66, 
	0x5A, 0x64, 0xD8, 0x42, 0x8B, 0x6B, 0x56, 0x0E, 0x15, 0x19, 
	0x94, 0x41, 0x62, 0xB4, 0x49, 0xA2, 0xAD, 0x96, 0x59, 0x6A, 
	0x68, 0x0C, 0x2D, 0x6A, 0x32, 0x33, 0x35, 0xBE, 0x77, 0xDF, 
	0xEB, 0xFB, 0xBE, 0x73, 0xEE, 0x7E, 0xEE, 0x9B, 0xFB, 0x96, 
	0xC9, 0xFE, 0xE8, 0x1C, 0xF4, 0xBD, 0x37, 0xF7, 0xDC, 0xF3, 
	0xFD, 0xBE, 0xE5, 0x7C, 0xDB, 0x01, 0xB2, 0x0D, 0x07, 0x39, 
	0xFF, 0xFB, 0x70, 0x4C, 0xC1, 0xB5, 0x78, 0x00, 0x4F, 0xE1, 
	0x05, 0xAC, 0xC7, 0x5A, 0xAC, 0xC0, 0x12, 0xDC, 0x8D, 0x59, 
	0x98, 0x80, 0x61, 0x7A, 0x85, 0x45, 0xAB, 0x6D, 0xD4, 0x6D, 
	0x38, 0x7A, 0xB3, 0x81, 0xB8, 0x10, 0x0F, 0xE3, 0x7D, 0x74, 
	0xA2, 0x88, 0x92, 0x61, 0xE6, 0xB1, 0x1F, 0x6F, 0xE3, 0x5E, 
	0x4C, 0xD6, 0x60, 0x1D, 0x9A, 0x75, 0x23, 0x3E, 0x1E, 0x4F, 
	0x60, 0x5F, 0x88, 0x98, 0x8B, 0x42, 0x6C, 0x86, 0x41, 0x7D, 
	0x8B, 0x87, 0x70, 0x56, 0xE4, 0xFD, 0xAA, 0x86, 0x45, 0xAF, 
	0x5B, 0xF4, 0x79, 0x09, 0xDE, 0x23, 0x02, 0x8A, 0x6C, 0x3E, 
	0x46, 0x2A, 0x3A, 0x8B, 0xF4, 0x34, 0xAF, 0x9F, 0xF7, 0xE2, 
	0x15, 0x4C, 0x0A, 0xED, 0x52, 0xF1, 0xB0, 0x45, 0x80, 0x13, 
	0xF1, 0xAE, 0xDE, 0x3A, 0x4F, 0xE4, 0x4B, 0x19, 0xA7, 0xEB, 
	0xC3, 0x78, 0x0D, 0x63, 0x0C, 0x72, 0xB0, 0xB3, 0x88, 0x1E, 
	0x18, 0x8C, 0x47, 0x71, 0x94, 0x36, 0x29, 0x68, 0xFE, 0x2B, 
	0x9B, 0x1E, 0xE4, 0x6E, 0xDC, 0x2F, 0x36, 0xE1, 0x84, 0xE4, 
	0xDA, 0xA7, 0xE8, 0xF9, 0x85, 0x73, 0xF1, 0x4D, 0xD5, 0xC4, 
	0x83, 0x59, 0x10, 0x10, 0x1F, 0xE2, 0x74, 0xDA, 0x31, 0x27, 
	0xBC, 0x33, 0xF7, 0x17, 0x63, 0x68, 0x5F, 0xE4, 0x5B, 0xD0, 
	0x23, 0x76, 0x5D, 0x4C, 0xE5, 0x4F, 0x99, 0x61, 0x5E, 0xAC, 
	0x82, 0xC9, 0x14, 0xCB, 0x48, 0xA2, 0x84, 0x43, 0xB8, 0x92, 
	0x76, 0x1D, 0x20, 0x92, 0x58, 0x8A, 0x23, 0x18, 0x21, 0x94, 
	0x52, 0x0C, 0x0F, 0x78, 0xB0, 0x0C, 0xEF, 0x6E, 0xAA, 0x35, 
	0x14, 0xCA, 0x3C, 0x29, 0xD2, 0xBC, 0x85, 0x76, 0x1E, 0x8B, 
	0x4F, 0xE8, 0xF7, 0xDF, 0xF4, 0x69, 0xB4, 0x04, 0x45, 0xFE, 
	0xC9, 0x14, 0xDE, 0xC3, 0x86, 0xD8, 0x83, 0x5D, 0xD8, 0x8C, 
	0x0E, 0xAC, 0xC4, 0x1A, 0xBC, 0x89, 0x8F, 0xB1, 0x57, 0xAC, 
	0xA5, 0x94, 0x0A, 0xDC, 0x95, 0xB7, 0x9F, 0xC3, 0x2F, 0xF4, 
	0x9D, 0x57, 0x4E, 0x0E, 0x59, 0x45, 0xCC, 0xF4, 0x16, 0xA6, 
	0x90, 0x57, 0xC7, 0xAF, 0x48, 0x96, 0xB1, 0x10, 0xD3, 0x31, 
	0x2A, 0xE4, 0x19, 0x95, 0x93, 0x3A, 0x13, 0x73, 0xF0, 0x3C, 
	0x0E, 0xF8, 0x5E, 0xC2, 0xA4, 0x34, 0x75, 0x50, 0xF9, 0x59, 
	0xB3, 0x09, 0x00, 0x6F, 0x79, 0x8F, 0x90, 0x4F, 0xE2, 0x2F, 
	0x88, 0xE0, 0x56, 0x91, 0x2F, 0x74, 0x22, 0x07, 0x55, 0xCD, 
	0x40, 0x9B, 0x43, 0x70, 0x0D, 0x99, 0x5C, 0x00, 0x38, 0xEE, 
	0x2B, 0x8B, 0xF2, 0xA4, 0x24, 0xEA, 0xC8, 0x25, 0xB9, 0xBF, 
	0x4A, 0x0B, 0xCB, 0xC4, 0xFB, 0x3A, 0xD1, 0x9B, 0x25, 0x46, 
	0xCA, 0xE7, 0xDA, 0x8A, 0x29, 0xCF, 0x96, 0xBF, 0xAB, 0x31, 
	0x1D, 0xDB, 0xFC, 0x13, 0x60, 0x72, 0xD9, 0x25, 0xB4, 0xC7, 
	0x01, 0xB0, 0x41, 0x34, 0xE1, 0x57, 0x01, 0x90, 0x5C, 0xFE, 
	0x13, 0x2E, 0xD7, 0x16, 0xE2, 0x64, 0x38, 0xC2, 0xB6, 0xB0, 
	0xD3, 0x86, 0xBF, 0x44, 0xE4, 0x66, 0x00, 0x8F, 0x9B, 0x00, 
	0x6C, 0x34, 0x88, 0x9F, 0x7F, 0xBF, 0x8E, 0x06, 0x59, 0x6E, 
	0x57, 0x10, 0x41, 0x18, 0xE8, 0x04, 0x7C, 0x69, 0x60, 0x48, 
	0xED, 0xB9, 0x26, 0x6A, 0x03, 0xFC, 0xF5, 0x56, 0xAD, 0x9D, 
	0xA8, 0xF0, 0x4B, 0x58, 0x9C, 0xCD, 0x7B, 0x19, 0x7C, 0x89, 
	0x43, 0xA1, 0xBA, 0x64, 0x30, 0x47, 0xFE, 0xCB, 0xA6, 0xF0, 
	0x31, 0x64, 0x6D, 0x36, 0x52, 0x28, 0x8D, 0x0B, 0x8C, 0x91, 
	0x2E, 0xA8, 0x90, 0x77, 0xCF, 0x1E, 0x80, 0xA9, 0x74, 0x34, 
	0xCD, 0x2A, 0x60, 0x99, 0x6C, 0x8B, 0x9B, 0xDF, 0xFC, 0x84, 
	0xF8, 0xF9, 0xD7, 0x32, 0x21, 0x6F, 0x55, 0x48, 0x1E, 0x38, 
	0x9E, 0xDE, 0xF4, 0x0E, 0x9E, 0x19, 0xC0, 0x1E, 0x0C, 0xF2, 
	0x7C, 0x21, 0xFF, 0x77, 0x0A, 0x7E, 0x8F, 0xA1, 0x65, 0x31, 
	0xBD, 0x23, 0xBC, 0x54, 0x4E, 0xFE, 0x44, 0x7C, 0xAA, 0x3D, 
	0xA6, 0xD9, 0x95, 0x17, 0xC5, 0x35, 0x37, 0x7A, 0x00, 0x58, 
	0x5B, 0x6D, 0x31, 0xFE, 0x79, 0x49, 0x27, 0x46, 0x67, 0x0B, 
	0x9C, 0x06, 0x13, 0x6C, 0xC2, 0x5C, 0x4A, 0x4A, 0xD2, 0xC2, 
	0x78, 0x51, 0xB2, 0x85, 0xA6, 0x60, 0xF7, 0xE3, 0xB0, 0x33, 
	0x66, 0xAD, 0xCC, 0x7F, 0x4B, 0xD2, 0x55, 0x54, 0x34, 0x06, 
	0x60, 0x1A, 0x5E, 0xA5, 0x60, 0x1C, 0xCD, 0x0F, 0x02, 0x08, 
	0xE7, 0x07, 0xE7, 0xE0, 0xB2, 0x18, 0x79, 0xFE, 0xBE, 0x25, 
	0x2D, 0x5A, 0x65, 0x4C, 0x66, 0x72, 0xE2, 0xB2, 0x80, 0xD3, 
	0x28, 0x47, 0xFC, 0x2E, 0x21, 0x0B, 0x66, 0x70, 0x46, 0x00, 
	0x60, 0x59, 0x4C, 0x01, 0xBC, 0x6C, 0x96, 0x39, 0x58, 0x54, 
	0x98, 0xD0, 0x39, 0x5A, 0xC2, 0x33, 0xB0, 0x41, 0xC2, 0xBB, 
	0x27, 0x0B, 0x06, 0x70, 0x93, 0x27, 0xE1, 0x1C, 0xBE, 0x8A, 
	0x48, 0x80, 0xBF, 0xED, 0xA8, 0x5B, 0x52, 0x1D, 0xC8, 0x62, 
	0x34, 0xE6, 0x51, 0x04, 0x55, 0xB2, 0x60, 0x1F, 0xD9, 0xE6, 
	0x01, 0x18, 0x17, 0x73, 0x99, 0x46, 0x4F, 0x5D, 0x37, 0x59, 
	0x34, 0xE3, 0x0D, 0xA2, 0xC7, 0x12, 0x58, 0xE4, 0xD1, 0x68, 
	0x89, 0xF0, 0xAF, 0xA2, 0xD5, 0xD9, 0x55, 0xDA, 0x7F, 0x36, 
	0x59, 0x8C, 0x21, 0x59, 0xFC, 0x41, 0x39, 0xB3, 0x56, 0xF2, 
	0x0A, 0xE1, 0xDA, 0xD5, 0x93, 0xF9, 0xFF, 0x42, 0x96, 0x59, 
	0xA8, 0xFF, 0xB0, 0xFC, 0xFC, 0x78, 0x28, 0xE5, 0x9C, 0x7A, 
	0x6C, 0x8D, 0x48, 0x80, 0x01, 0x3C, 0x5B, 0xB3, 0x01, 0x66, 
	0x91, 0x85, 0x3F, 0x76, 0x50, 0x9A, 0xF4, 0xB3, 0x3F, 0xF7, 
	0xE0, 0x4F, 0xDC, 0xD8, 0xCF, 0x00, 0x82, 0x78, 0xA1, 0x73, 
	0x98, 0xC1, 0xF2, 0xCF, 0x9B, 0x43, 0xFA, 0x9D, 0xF8, 0x7F, 
	0x6D, 0x58, 0x89, 0xF9, 0xFF, 0x38, 0x46, 0x8A, 0x38, 0xE6, 
	0x0A, 0xB7, 0xFF, 0x05, 0xEB, 0x2F, 0xC3, 0xE6, 0x28, 0x5D, 
	0xBB, 0xE6, 0xFA, 0x55, 0x16, 0x36, 0x45, 0x83, 0xE8, 0x1C, 
	0xE4, 0xE5, 0x84, 0x2F, 0x52, 0x9A, 0x38, 0x55, 0x9C, 0x83, 
	0xD5, 0x4F, 0x20, 0x98, 0xCA, 0x1D, 0x54, 0x79, 0x7C, 0x8F, 
	0xDD, 0x7A, 0xFE, 0x40, 0x6E, 0x6F, 0xAB, 0x97, 0x94, 0x3D, 
	0x22, 0x41, 0xE8, 0x73, 0x5C, 0x47, 0x55, 0x5E, 0xDD, 0xBB, 
	0x5C, 0xBE, 0xF8, 0x3F, 0x8A, 0xA4, 0xE9, 0xFC, 0x6D, 0x83, 
	0x07, 0x60, 0xAE, 0xE4, 0x69, 0x1C, 0x0B, 0x77, 0xE1, 0x4E, 
	0x69, 0x1F, 0x58, 0xB5, 0x35, 0x98, 0x12, 0xC2, 0xE7, 0x8C, 
	0xA0, 0x4B, 0x17, 0x6C, 0x41, 0xE0, 0xBB, 0xCB, 0x03, 0x70, 
	0x83, 0x2E, 0xAC, 0x55, 0x1D, 0x78, 0x80, 0x02, 0xE6, 0xC8, 
	0x8C, 0xC5, 0x58, 0xB6, 0xC1, 0x34, 0x6E, 0x4B, 0x94, 0x29, 
	0x79, 0x69, 0x63, 0x09, 0x89, 0x69, 0xFE, 0x43, 0x57, 0x83, 
	0x38, 0x44, 0xF5, 0xDB, 0x98, 0xBA, 0x81, 0x60, 0x05, 0x6C, 
	0x8E, 0x00, 0x70, 0x45, 0xDA, 0x83, 0x3C, 0xF1, 0x4C, 0x8A, 
	0x64, 0x45, 0x5E, 0x16, 0xDB, 0x83, 0x97, 0x74, 0xDC, 0xAE, 
	0xED, 0x90, 0x3A, 0xD2, 0xEC, 0x8B, 0x56, 0x1E, 0xAC, 0x80, 
	0x67, 0x02, 0xFD, 0x9C, 0x41, 0x16, 0x50, 0x8A, 0xA5, 0xCE, 
	0x0A, 0x44, 0x1E, 0x6F, 0xE1, 0x22, 0xDF, 0x89, 0x54, 0x6F, 
	0x01, 0x1B, 0x63, 0x0A, 0x70, 0x75, 0x9B, 0x42, 0x8B, 0x67, 
	0x38, 0x0E, 0x1A, 0x2A, 0xB9, 0x20, 0x95, 0xDE, 0x42, 0x8B, 
	0xAD, 0x1A, 0xF4, 0x3F, 0xDB, 0x90, 0xFA, 0xEF, 0xA6, 0xD0, 
	0xEF, 0x03, 0x18, 0x48, 0x67, 0xB2, 0x94, 0xDA, 0x62, 0x52, 
	0x4D, 0x8B, 0xED, 0x38, 0xA9, 0x0A, 0xA7, 0xCD, 0xDC, 0x8F, 
	0x4C, 0xEC, 0xCE, 0x0A, 0x98, 0x17, 0x4D, 0x7D, 0xB7, 0xA5, 
	0x02, 0x50, 0x07, 0xE6, 0x47, 0x69, 0xB4, 0x55, 0x97, 0xF9, 
	0x74, 0xC4, 0xC4, 0xCF, 0xEC, 0x1C, 0x24, 0xEF, 0xEB, 0xA7, 
	0xBE, 0xFC, 0xB1, 0xC9, 0x58, 0xCB, 0x7B, 0xCB, 0x5F, 0x96, 
	0x26, 0x85, 0x55, 0x31, 0x79, 0xE6, 0x70, 0x89, 0xB1, 0xF2, 
	0x9E, 0x1F, 0x4E, 0xFC, 0xF8, 0xCB, 0x5A, 0x63, 0x7B, 0x8A, 
	0x89, 0xEF, 0xC3, 0x9C, 0xAA, 0xCE, 0x81, 0x7A, 0x63, 0x41, 
	0x62, 0x5F, 0x96, 0xF3, 0x5E, 0xAA, 0xA1, 0x43, 0x0C, 0x31, 
	0xCE, 0xA5, 0x46, 0x00, 0x2C, 0x93, 0x95, 0x02, 0x71, 0x40, 
	0x15, 0xBC, 0xDB, 0x78, 0x3A, 0xA5, 0xEF, 0x72, 0x7D, 0x34, 
	0xF1, 0xE5, 0xC5, 0xF7, 0x19, 0x01, 0x28, 0xBC, 0x1F, 0x50, 
	0x91, 0x99, 0xFD, 0x02, 0xC2, 0x73, 0x5D, 0xA3, 0xE9, 0x3D, 
	0x73, 0xD7, 0x69, 0x75, 0x3C, 0xEF, 0x66, 0x00, 0xAD, 0xA9, 
	0x36, 0xE0, 0x8A, 0x5F, 0x6C, 0x15, 0x4B, 0xB1, 0xFB, 0x08, 
	0x53, 0x5E, 0x40, 0x77, 0x70, 0x3B, 0xBD, 0x93, 0x24, 0xCF, 
	0x14, 0x76, 0x06, 0xCD, 0x89, 0xB0, 0x0D, 0xCC, 0xD4, 0x8F, 
	0x5D, 0x43, 0x5F, 0xA3, 0xA0, 0xFB, 0x3A, 0xCD, 0x1A, 0xB7, 
	0xAD, 0x7B, 0x85, 0xB6, 0xCE, 0x6A, 0x6C, 0xB9, 0x53, 0xF2, 
	0xC2, 0x78, 0x0E, 0x57, 0x53, 0x5C, 0x35, 0xF5, 0x4B, 0x79, 
	0x97, 0xC3, 0x18, 0x9F, 0x2C, 0xFC, 0x78, 0xDB, 0x0B, 0x42, 
	0xAF, 0xB8, 0x06, 0x97, 0xA4, 0x9E, 0x6C, 0xA7, 0x58, 0x39, 
	0x2A, 0xF5, 0x3C, 0x58, 0x18, 0x4B, 0x85, 0xED, 0xD7, 0x29, 
	0x9D, 0x52, 0xDE, 0xB5, 0x17, 0x57, 0x98, 0x0A, 0x5F, 0xC6, 
	0x73, 0x8E, 0x34, 0xDE, 0x4B, 0x54, 0xAC, 0xB7, 0x53, 0x75, 
	0x64, 0x6E, 0xAF, 0x29, 0x3F, 0xD1, 0x45, 0xBA, 0x5D, 0x40, 
	0x5C, 0x9E, 0x87, 0x53, 0xC9, 0x96, 0x87, 0x61, 0x04, 0x39, 
	0xF2, 0x29, 0x54, 0x4F, 0x2D, 0x23, 0xBE, 0xF3, 0xA9, 0x0D, 
	0xEB, 0x82, 0xF8, 0xD5, 0x99, 0xE6, 0xBA, 0x9B, 0xF9, 0x39, 
	0x19, 0x47, 0x68, 0xD9, 0x0A, 0x39, 0xEF, 0x97, 0x92, 0xA0, 
	0xD2, 0x4C, 0x32, 0x1F, 0x92, 0x4A, 0x37, 0xB9, 0x93, 0xDF, 
	0x08, 0x6E, 0xAF, 0xB1, 0xA3, 0x1E, 0x37, 0xBD, 0xC3, 0x98, 
	0x9E, 0x56, 0xF6, 0x33, 0x80, 0x06, 0x7C, 0x26, 0x7D, 0x11, 
	0x5B, 0x0E, 0xDC, 0x04, 0x69, 0x26, 0x98, 0x37, 0x53, 0x57, 
	0x53, 0x85, 0x58, 0xE8, 0x52, 0xB7, 0x05, 0xC5, 0x54, 0xD0, 
	0xBB, 0x30, 0xAE, 0x7C, 0xD7, 0x21, 0x87, 0x13, 0xC4, 0x1A, 
	0x2C, 0x6D, 0x13, 0xC3, 0xB0, 0x2E, 0x94, 0x1D, 0xA4, 0xDD, 
	0x86, 0x78, 0xB3, 0xDC, 0xCD, 0x11, 0x3F, 0x5D, 0x25, 0x97, 
	0x9A, 0x4E, 0xDF, 0xE7, 0x37, 0xB0, 0x0A, 0xB6, 0x8B, 0x9B, 
	0xD1, 0x99, 0x72, 0x2E, 0x2A, 0xB9, 0xB6, 0xDA, 0x4F, 0x99, 
	0xA6, 0xB7, 0x63, 0x05, 0x59, 0xBB, 0x82, 0xD3, 0x88, 0xE5, 
	0x72, 0xC3, 0x51, 0xD4, 0x26, 0x9A, 0x95, 0xB4, 0x97, 0xDC, 
	0x75, 0x61, 0x91, 0x58, 0x55, 0x95, 0x77, 0x87, 0x2A, 0x2D, 
	0x1D, 0x4B, 0x99, 0x4B, 0xB7, 0xCF, 0x53, 0x79, 0x95, 0xB8, 
	0x1A, 0xA8, 0x8A, 0x77, 0x8F, 0xE9, 0x88, 0xE7, 0xD4, 0x92, 
	0xCD, 0x3A, 0xBA, 0xC7, 0xD5, 0x4E, 0x3E, 0xA0, 0x68, 0xB8, 
	0xBA, 0x75, 0xFD, 0xCF, 0xE0, 0xE9, 0x51, 0x4A, 0xC0, 0x5B, 
	0xB5, 0xBF, 0x73, 0x6A, 0xAF, 0x32, 0x6C, 0xDF, 0xFF, 0x4D, 
	0x44, 0x1B, 0x25, 0x68, 0x07, 0x52, 0x95, 0xD1, 0x4D, 0x5E, 
	0x64, 0x35, 0x5A, 0x24, 0x99, 0xAD, 0xF9, 0xE6, 0x38, 0xBD, 
	0xAF, 0xD3, 0x40, 0x40, 0x66, 0x53, 0x3E, 0xB3, 0x9C, 0x52, 
	0xD6, 0x0E, 0x02, 0xB4, 0x9E, 0xEA, 0xAA, 0xC5, 0xE4, 0x21, 
	0x9B, 0xD1, 0xE4, 0x0B, 0x3B, 0x73, 0x91, 0xF7, 0x0F, 0x76, 
	0x23, 0xA9, 0xBF, 0x46, 0x38, 0x2F, 0xFF, 0x00, 0x00, 0x00, 
	0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, };

wxBitmap& channel_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( channel_png, sizeof( channel_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
}


#endif //CHANNEL_PNG_H
