//
//   
//  Sparrow
//
//  Created by Daniel Sperl on 15.03.09.
//  Copyright 2009 Incognitek. All rights reserved.
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the Simplified BSD License.
//

#import <Foundation/Foundation.h>
#import "SPDisplayObject.h"

typedef enum 
{
    SPGradientHorizontal = 0,
    SPGradientVertical
} SPGradientStyle;

/** ------------------------------------------------------------------------------------------------

 An SPQuad represents a rectangle with a uniform color or a color gradient. 
 
 You can set one color per vertex. The colors will smoothly fade into each other over the area
 of the quad. To display a simple linear color gradient, assign one color to vertices 0 and 1 and 
 another color to vertices 2 and 3.
 
 The indices of the vertices are arranged like this:
 
	0 - 1
	| / |
	2 - 3
 
 **Colors**
 
 Colors in Sparrow are defined as unsigned integers, that's exactly 8 bit per color. The easiest
 way to define a color is by writing it as a hexadecimal number. A color has the following
 structure:
 
	0xRRGGBB
 
 That means that you can create the base colors like this:
 
	0xFF0000 -> red
 	0x00FF00 -> green
 	0x0000FF -> blue
 
 Other simple colors:
 
	0x000000 or 0x0 -> black
	0xFFFFFF        -> white
	0x808080        -> 50% gray
 
 If you're not comfortable with that, there is also a utility macro available that takes the
 values for R, G and B separately:
 
	uint red = SP_COLOR(255, 0, 0)
 
------------------------------------------------------------------------------------------------- */

@interface SPQuad : SPDisplayObject 
{
  @protected
	BOOL mFill;
	float mDefaultVertexCoords[8];
    float mVertexCoords[8];
    uint mVertexColors[4];
	float mVertexAlpha[4];
	BOOL mBorder;
	float mBorderWidth;
	float mDefaultBorderVertexCoords[8];
	float mBorderVertexCoords[8];
	uint mBorderVertexColors[4];
	float mBorderVertexAlpha[4];
	float mScewX1;
	float mScewX2;
	float mScewY1;
	float mScewY2;
}

@property (nonatomic, assign) BOOL fill;
@property (nonatomic, assign) uint color;
@property (nonatomic, assign) BOOL border;
@property (nonatomic, assign) uint borderColor;
@property (nonatomic, assign) float borderWidth;
@property (nonatomic, assign) float scewX1;
@property (nonatomic, assign) float scewX2;
@property (nonatomic, assign) float scewY1;
@property (nonatomic, assign) float scewY2;
@property (nonatomic, assign) float *scew;

- (id)initWithWidth:(float)width height:(float)height; 
- (void)setColor:(uint)color ofVertex:(int)vertexID;
- (void)setRedColor:(int)redColor ofVertex:(int)vertexID;
- (void)setGreenColor:(int)greenColor ofVertex:(int)vertexID;
- (void)setBlueColor:(int)blueColor ofVertex:(int)vertexID;
- (void)setBorderColor:(uint)borderColor ofVertex:(int)vertexID;

- (void)setGradientStartColor:(uint)startColor endColor:(uint)endColor withStyle:(int)style;
- (void)setGradientStartColor:(uint)startColor startAlpha:(float)startAlpha endColor:(uint)endColor withStyle:(int)style;
- (void)setGradientStartColor:(uint)startColor endColor:(uint)endColor endAlpha:(float)endAlpha withStyle:(int)style;
- (void)setGradientStartColor:(uint)startColor startAlpha:(float)startAlpha endColor:(uint)endColor endAlpha:(float)endAlpha withStyle:(int)style;
- (void)setBorderGradientStartColor:(uint)startColor endColor:(uint)endColor withStyle:(int)style;
- (void)setBorderGradientStartColor:(uint)startColor startAlpha:(float)startAlpha endColor:(uint)endColor withStyle:(int)style;
- (void)setBorderGradientStartColor:(uint)startColor endColor:(uint)endColor endAlpha:(float)endAlpha withStyle:(int)style;
- (void)setBorderGradientStartColor:(uint)startColor startAlpha:(float)startAlpha endColor:(uint)endColor endAlpha:(float)endAlpha withStyle:(int)style;

- (uint)colorOfVertex:(int)vertexID;
- (uint)colorOfBorderVertex:(int)vertexID;

+ (SPQuad*)quadWithWidth:(float)width height:(float)height;

/// Factory method.
+ (SPQuad*)quadWithWidth:(float)width height:(float)height color:(uint)color;

/// Factory method. Creates a 32x32 quad.
+ (SPQuad*)quad;

/// ----------------
/// @name Properties
/// ----------------

/// Sets the colors of all vertices simultaneously. Returns the color of vertex '0'.
//@property (nonatomic, assign) uint color;

@end
