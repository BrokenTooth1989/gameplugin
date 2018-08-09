//
//  IETPromotionHelper.h
//  blackjack
//
//  Created by joye on 2018/8/7.
//

#ifndef IETPromotionHelper_h
#define IETPromotionHelper_h
#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

@interface IETPromotionHelper : NSObject <SKPaymentTransactionObserver>

@property(nonatomic, copy) void (^promotionHandler)(NSArray*);

+ (IETPromotionHelper*)getInstance;

/**
 *  获取 appstore promotion 清单
 *  @param handler 回调
 */
- (void)fetchStorePromotionOrder:(void(^)(NSArray*))handler;

/**
 *  更新 appstore promotion 清单(显示顺序)
 *  @param productArray product array
 *  @param handler 回调
 */
- (void)updateStorePromotionOrder:(NSArray*) productArray handler:(void(^)(NSArray*))handler;

/**
 *  获取某个product 在appstore promotion 当前的状态（是否在展示）
 *  @param iapId iapId
 *  @param handler 回调
 */
- (void)fetchStorePromotionVisibility:(NSString*) iapId handler:(void(^)(NSArray*))handler;

/**
 *  刷新product 在appstore promotion 当前的状态（是否在展示）
 *  @param iapId iapId
 *  @param handler 回调
 */
- (void)updateStorePromotionVisibility:(NSString*) iapId visibilty:(NSInteger)visibilty handler:(void(^)(NSArray*))handler;

@end

#endif /* IETPromotionHelper_h */
