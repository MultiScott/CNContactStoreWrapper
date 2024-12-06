//
//  CNContactStoreWrapper.h
//  CNContactStoreWrapper
//
//  Created by Scott Hoge on 12/5/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class CNContactStore;
@class CNChangeHistoryFetchRequest;
@class CNFetchResult;

@interface CNContactStoreWrapper : NSObject
- (instancetype)initWithStore:(CNContactStore *)store NS_DESIGNATED_INITIALIZER;

- (CNFetchResult *)changeHistoryFetchResult:(CNChangeHistoryFetchRequest *)request
                                      error:(NSError *__autoreleasing  _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
