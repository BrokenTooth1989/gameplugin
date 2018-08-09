//
//  IETPromotionHelper.m
//  blackjack
//
//  Created by joye on 2018/8/7.
//

#import "IETPromotionHelper.h"
#import "RMStore.h"

#pragma mark - IETPromotionHelper

//#if ! __has_feature(objc_arc)
//#error This file must be compiled with ARC. Either turn on ARC for the project or use -fobjc-arc flag
//#endif

@implementation IETPromotionHelper

@synthesize promotionHandler;

static IETPromotionHelper* _instance = nil;

+ (IETPromotionHelper*)getInstance {
    if (_instance == nil) {
        _instance = [[IETPromotionHelper alloc] init];
    }
    return _instance;
}

- (instancetype)init {
    if (self = [super init]) {
        [[SKPaymentQueue defaultQueue] addTransactionObserver:self];
        return self;
    }
    return nil;
}

- (void)dealloc
{
    [[SKPaymentQueue defaultQueue] removeTransactionObserver:self];
}

#pragma mark SKPaymentTransactionObserver

- (BOOL)paymentQueue:(SKPaymentQueue *)queue shouldAddStorePayment:(SKPayment *)payment forProduct:(SKProduct *)product{
    NSMutableArray *playerInfos = [NSMutableArray array];
    [playerInfos addObject:@{@"iapId":product.productIdentifier, @"price":product.price, @"title":product.localizedTitle}];
    if (self.promotionHandler!=nil){
        self.promotionHandler([NSArray arrayWithArray:playerInfos]);
    }
    return NO;
}

#pragma mark SKProductStorePromotionController
-  (void)fetchStorePromotionOrder:(void(^)(NSArray*))handler{
    //FIXME: unfinish
    if (@available(iOS 11.0, *)) {
        [[SKProductStorePromotionController defaultController] fetchStorePromotionOrderWithCompletionHandler:^(NSArray<SKProduct *> * storePromotionOrder, NSError * error) {
        
            if(error)
            {
                handler(nil);
            }
            else
            {
                int count = (int)storePromotionOrder.count;
                NSArray *orderArr = [NSArray array];
                for (int i = 0; i<count; i++)
                {
                    SKProduct *obj = [storePromotionOrder objectAtIndex:i];
                    NSMutableArray *product = [NSMutableArray array];
                    [product addObject:@{@"iapId":obj.productIdentifier, @"price":obj.price, @"title":obj.localizedTitle}];
                    [orderArr arrayByAddingObject: [NSArray arrayWithArray:product]];
                }
                handler(orderArr);
            }
        }];
    } else {
        // Fallback on earlier versions
    }
}

- (void)updateStorePromotionOrder:(NSArray*) productArray handler:(void(^)(NSArray*))handler
{
    if (@available(iOS 11.0, *)) {
        //FIXME: unfinish
        [[SKProductStorePromotionController defaultController] updateStorePromotionOrder:productArray
                                                                       completionHandler:^(NSError * error) {
                                                                           if(error)
                                                                           {
                                                                               handler(nil);
                                                                           }
                                                                           else
                                                                           {
                                                                           }
                                                                       }];
    } else {
        // Fallback on earlier versions
    }
}

- (void)fetchStorePromotionVisibility:(NSString*) iapId handler:(void(^)(NSArray*))handler
{
    if (@available(iOS 11.0, *)) {
        [[RMStore defaultStore] requestProducts:[[NSSet alloc] initWithObjects:iapId, nil]
                                        success:^(NSArray *products, NSArray *invalidProductIdentifiers) {
                                            if ([products count] > 0) {
                                                SKProduct *skproduct = [[RMStore defaultStore] productForIdentifier:iapId];
                                                [[SKProductStorePromotionController defaultController] fetchStorePromotionVisibilityForProduct:skproduct
                                                                                                                                 completionHandler:^(SKProductStorePromotionVisibility storePromotionVisibility, NSError * _Nullable error) {
                                                                                                                                     if(error)
                                                                                                                                     {
                                                                                                                                         NSMutableArray *result = [NSMutableArray array];
                                                                                                                                         [result addObject:@{@"result":@false}];
                                                                                                                                         handler([NSArray arrayWithArray:result]);
                                                                                                                                     }
                                                                                                                                     else
                                                                                                                                     {
                                                                                                                                         NSMutableArray *result = [NSMutableArray array];
                                                                                                                                         NSInteger vis = storePromotionVisibility;
                                                                                                                                         [result addObject:@{@"result":@true,@"visibility":[NSNumber numberWithInt:vis]}];
                                                                                                                                         NSArray *arr = [NSArray arrayWithArray:result];
                                                                                                                                         handler(arr);
                                                                                                                                     }
                                                                                                                                 }];
                                         
                                            } else {
                                                NSMutableArray *result = [NSMutableArray array];
                                                [result addObject:@{@"result":@false}];
                                                handler([NSArray arrayWithArray:result]);
                                            }
                                        } failure:^(NSError *error) {
                                            NSMutableArray *result = [NSMutableArray array];
                                            [result addObject:@{@"result":@false}];
                                            handler([NSArray arrayWithArray:result]);
                                        }];
        
     }else
     {
         
     }
}

- (void)updateStorePromotionVisibility:(NSString*) iapId  visibilty:(NSInteger)visibilty handler:(void(^)(NSArray*))handler
{
    if (@available(iOS 11.0, *)) {
        [[RMStore defaultStore] requestProducts:[[NSSet alloc] initWithObjects:iapId, nil]
                                        success:^(NSArray *products, NSArray *invalidProductIdentifiers) {
                                            if ([products count] > 0) {
                                                SKProduct *skproduct = [[RMStore defaultStore] productForIdentifier:iapId];
                                                [[SKProductStorePromotionController defaultController] updateStorePromotionVisibility:visibilty
                                                                                                                           forProduct:skproduct
                                                                                                                    completionHandler:^(NSError * error) {
                                                                                                                        if(error)
                                                                                                                        {
                                                                                                                            NSMutableArray *result = [NSMutableArray array];
                                                                                                                            [result addObject:@{@"result":@false}];
                                                                                                                            handler([NSArray arrayWithArray:result]);
                                                                                                                        }
                                                                                                                        else
                                                                                                                        {
                                                                                                                            NSMutableArray *result = [NSMutableArray array];
                                                                                                                            [result addObject:@{@"result":@true}];
                                                                                                                            handler([NSArray arrayWithArray:result]);
                                                                                                                        }
                                                                                                                    }];
                                            }else
                                                {
                                                    NSMutableArray *result = [NSMutableArray array];
                                                    [result addObject:@{@"result":@true}];
                                                    handler([NSArray arrayWithArray:result]);
                                                }
                                            } failure:^(NSError *error) {
                                                NSMutableArray *result = [NSMutableArray array];
                                                [result addObject:@{@"result":@true}];
                                                handler([NSArray arrayWithArray:result]);
                                            }];
                                            
    } else {
        // Fallback on earlier versions
    }
}

@end
