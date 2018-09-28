//
//  ASRotationPageView.h
//  HeJiaKang
//
//  Created by OneForAll on 2017/12/15.
//  Copyright © 2017年 OneForAll. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ASRotationScrollDirection) {
    /** 水平滚动*/
    ASRotationScrollDirectionHorizontal,
    /** 垂直滚动*/
    ASRotationScrollDirectionVertical,
};
typedef NS_ENUM(NSInteger, ASRotationPageViewAlign) {
    ASRotationPageViewAlignVerticalCenter,
};

@interface ASRotationPageView : UIView


/** 无限轮播 - 默认YES */
@property (nonatomic, assign) BOOL  infiniteSliding;

/** 自动轮播 - 默认YES */
@property (nonatomic, assign) BOOL autoSliding;

/** 轮播图滚动时间间隔 - 默认是5秒 */
@property (nonatomic, assign) NSTimeInterval scrollTimeInterval;


/** 手动滑动  默认yes */
@property (nonatomic, assign) BOOL scrollEnabled;

/** 滚动方向 - 默认横向滚动 */
@property (nonatomic, assign) ASRotationScrollDirection scrollDirection;

/** 当前的页码 */
@property (nonatomic, assign) NSUInteger currentPage;

/** 图片未加载出来的占位图 */
@property (nonatomic, copy) NSString *placeholderName;
/** 滑动完成的回调 */
@property (nonatomic, copy) void(^ScrollDidEnd)(NSUInteger currentPage);
/** 点击view的回调 */
@property (nonatomic, copy) void(^SelectView)(NSInteger index);

/** 偏移到制定页 */
@property (nonatomic, assign) NSUInteger contentOffsetPage;




/**
 初始化方法

 @param frame frame
 @param images 图片url或图片名称或UIView
 @return 对象
 */
- (instancetype)initWithFrame:(CGRect)frame images:(NSArray *)images;


/** 开始   必须调用此方法 否则无视图  设置完各参数最后调用生效*/
- (void)showStart;
@end
