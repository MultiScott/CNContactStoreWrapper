//
//  CNContactStoreWrapper.m
//  CNContactStoreWrapper
//
//  Created by Scott Hoge on 12/5/24.
//

#import "CNContactStoreWrapper.h"
@import Contacts;

@interface CNContactStoreWrapper ()
@property (nonatomic, strong) CNContactStore *store;
@end

@implementation CNContactStoreWrapper

- (instancetype)init {
    return [self initWithStore:[[CNContactStore alloc] init]];
}

- (instancetype)initWithStore:(CNContactStore *)store {
    if (self = [super init]) {
        _store = store;
    }
    return self;
}

- (CNFetchResult *)changeHistoryFetchResult:(CNChangeHistoryFetchRequest *)request
                                      error:(NSError *__autoreleasing  _Nullable * _Nullable)error {
    CNFetchResult *fetchResult = [self.store enumeratorForChangeHistoryFetchRequest:request error:error];
    return fetchResult;
}
@end
