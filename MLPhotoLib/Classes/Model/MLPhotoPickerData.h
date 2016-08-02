//
//  MLPhotoPickerData.h
//  MLPhotoLib
//
//  Created by leisuro on 16/8/1.
//  Copyright © 2016年 Free. All rights reserved.
//

#import <Foundation/Foundation.h>

///iOS8之前
// 选择相片完回调
typedef void(^MLPhotoPickerDataPhotoCallBack)(NSArray *array);

@class MLPhotoPickerGroup;
@interface MLPhotoPickerData : NSObject

+ (instancetype)pickerData;
/// 获取所有相册组
- (void)getAllGroup:(MLPhotoPickerDataPhotoCallBack)callBack;
/// 获取所有组对应的图片与视频
- (void)getAllGroupWithPhotosAndVideos:(MLPhotoPickerDataPhotoCallBack)callBack;
/// 获取所有组对应的图片
- (void)getAllGroupWithPhotos:(MLPhotoPickerDataPhotoCallBack)callBack;
/// 获取所有组对应的Videos
- (void)getAllGroupWithVideos:(MLPhotoPickerDataPhotoCallBack)callBack;
/// 传入一个组获取组里面的Asset
- (void)getGroupPhotosWithGroup:(MLPhotoPickerGroup *)pickerGroup finished:(MLPhotoPickerDataPhotoCallBack)callBack;
/// 传入一个AssetsURL来获取UIImage
- (void)getAssetsPhotoWithURLs:(NSURL *)url callBack:(MLPhotoPickerDataPhotoCallBack)callBack;

@end

@class UIImage, ALAssetsGroup;
@interface MLPhotoPickerGroup : NSObject
// 组名
@property (copy,nonatomic) NSString *groupName;
// 缩略图
@property (strong,nonatomic) UIImage *thumbImage;
// 组里面的图片个数
@property (assign,nonatomic) NSInteger assetsCount;
// 相机胶卷, xx
@property (strong,nonatomic) NSNumber *type;
// 包装的group
@property (strong,nonatomic) ALAssetsGroup *group;
// 是否是视频
@property (assign,nonatomic) BOOL isVideo;
@end