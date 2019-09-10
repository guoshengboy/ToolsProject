//
//  GSMacro.h
//  Tool
//
//  Created by caoguosheng on 2019/9/10.
//  Copyright © 2019 caoguosheng. All rights reserved.
//

#ifndef GSMacro_h
#define GSMacro_h


#pragma mark - UI

//NavBar高度
#define NavBarHeight 44

//StatusBar高度
#define StatusBarHeight [[UIApplication sharedApplication] statusBarFrame].size.height

//状态栏 ＋ 导航栏 高度
#define NavHeight ((NavBarHeight) + (StatusBarHeight))

//获取屏幕 宽度、高度
#define ScreenWidth ([UIScreen mainScreen].bounds.size.width)
#define ScreenHeight ([UIScreen mainScreen].bounds.size.height)

//KWindow
#define KWindow [UIApplication sharedApplication].keyWindow

#pragma mark - Log

//(在系统Log基础之上，加入自定义的相关信息)
#ifdef DEBUG
#define Plog(...) NSLog(__VA_ARGS__)
#else
#define Plog(...)
#endif

#ifdef DEBUG
#define NSLog(format, ...) printf("[%s] %s [第%d行] %s\n", __TIME__, __FUNCTION__, __LINE__, [[NSString stringWithFormat:format, ## __VA_ARGS__] UTF8String]);
#else
#define NSLog(format, ...)
#endif

#ifdef DEBUG
#define LFLog(...) printf("[%s] %s [第%d行]: %s\n", __TIME__ ,__PRETTY_FUNCTION__ ,__LINE__, [[NSString stringWithFormat:__VA_ARGS__] UTF8String])
#else
#define LFLog(...)
#endif

#pragma mark - System

//获取当前系统版本
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion [[UIDevice currentDevice] systemVersion]

#pragma mark - Notification

//快速发通知
#define NotificatioPost(_notificationName, _obj, _userInfoDictionary) [[NSNotificationCenter defaultCenter] postNotificationName: _notificationName object: _obj userInfo: _userInfoDictionary];

//添加观察者
#define NotificationAddObserver(_notificationName, _observer, _observerSelector, _obj) [[NSNotificationCenter defaultCenter] addObserver:_observer selector:@selector(_observerSelector) name:_notificationName object: _obj];

//移除观察者
#define NotificationRemoveObserver(_observer) [[NSNotificationCenter defaultCenter] removeObserver: _observer];


#pragma mark - Block
#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;
//弱引用
#define WeakWithNameAndObject(obj,name)   __weak   typeof(obj) weak##name   = obj
//强引用
#define StrongWithNameAndObject(obj,name) __strong typeof(obj) strong##name = obj

#endif /* GSMacro_h */
