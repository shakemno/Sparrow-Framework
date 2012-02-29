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

@end
