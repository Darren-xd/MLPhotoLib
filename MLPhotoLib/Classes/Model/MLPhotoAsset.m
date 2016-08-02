//
//  MLPhotoAsset.m
//  MLPhotoLib
//
//  Created by leisuro on 16/8/1.
//  Copyright © 2016年 Free. All rights reserved.
//

#import "MLPhotoAsset.h"

@interface MLPhotoAsset ()
@property (nonatomic, assign) BOOL isUIImage;
@end

@implementation MLPhotoAsset

+ (instancetype)assetWithImage:(UIImage *)image
{
    MLPhotoAsset *asset = [[MLPhotoAsset alloc] init];
    asset.isUIImage = YES;
    asset.thumbImage = image;
    asset.originImage = image;
    asset.aspectRatioImage = image;
    return asset;
}

- (UIImage *)aspectRatioImage
{
    return self.isUIImage ? _aspectRatioImage : [UIImage imageWithCGImage:[self.asset aspectRatioThumbnail]];
}

- (UIImage *)thumbImage
{
    return self.isUIImage ? _thumbImage : self.aspectRatioImage;
}

- (UIImage *)originImage
{
    return self.isUIImage ? _originImage : [UIImage imageWithCGImage:[[self.asset defaultRepresentation] fullScreenImage]];
}

- (BOOL)isVideoType{
    NSString *type = [self.asset valueForProperty:ALAssetPropertyType];
    //媒体类型是视频
    return [type isEqualToString:ALAssetTypeVideo];
}

- (NSURL *)assetURL{
    return [[self.asset defaultRepresentation] url];
}

@end
