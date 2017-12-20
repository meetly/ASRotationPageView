# ASRotationPageView
轮播图 引导图  横向滑动 纵向滑动

## 特点
  1.可用作轮播图，引导页， 轮播广告<br>
  2.可将view用作轮播<br>
  3.可横向滑动和纵向滑动<br>
## 演示 
   横向滑动
   <img src="https://github.com/meetly/ASRotationPageView/blob/master/images/horizontal.gif" width="300" height="650" alt="横向滑动"/>
   纵向滑动
    <img src="https://github.com/meetly/ASRotationPageView/blob/master/images/vertical.gif" width="300" height="650" alt="横向滑动"/>
    
## 方法介绍 
```
/** 无限轮播 - 默认YES */
@property (nonatomic, assign) BOOL  infiniteSliding;

/** 自动轮播 - 默认YES */
@property (nonatomic, assign) BOOL autoSliding;

/** 轮播图滚动时间间隔 - 默认是5秒 */
@property (nonatomic, assign) NSTimeInterval scrollTimeInterval;

/** 滚动方向 - 默认横向滚动 */
@property (nonatomic, assign) ASRotationScrollDirection scrollDirection;

/** 当前的页码 */
@property (nonatomic, assign) NSUInteger currentPage;

/** 图片未加载出来的占位图 */
@property (nonatomic, copy) NSString *placeholderName;
/** 滑动完成的回调 */
@property (nonatomic, copy) void(^ScrollDidEnd)(NSUInteger currentPage);
/** 点击view的回调 */
@property (nonatomic, copy) void(^SelectView)(UIView *view);

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
```
## 使用说明
  将ASRotationPageView文件夹导入到工程中，并引入头文件#import "ASRotationPageView.h"
```
    self.rotaView = [[ASRotationPageView alloc] initWithFrame:self.view.bounds images:@[@"png1", @"png2", @"png3"]];
    self.rotaView.scrollDirection = ASRotationScrollDirectionHorizontal;
    self.rotaView.infiniteSliding = NO;
    self.rotaView.autoSliding = YES;
    self.rotaView.ScrollDidEnd = ^(NSUInteger currentPage) {
        weakself.pageView.currentPage = currentPage;
    };
    self.rotaView.SelectView = ^(UIView *view) {};
    [self.rotaView showStart];
    [self.view addSubview:self.rotaView];
```
## 建议配合ASPageView使用（可自定义的pageViewController）
  [ASPageView地址：https://github.com/meetly/ASPageView](https://github.com/meetly/ASPageView) 
