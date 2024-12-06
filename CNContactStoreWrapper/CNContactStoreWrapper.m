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

/// Initializes the wrapper with a specific `CNContactStore` instance.
///
/// - Parameter store: A `CNContactStore` instance to be used by this wrapper.
///
/// - Note: For more information, see [CNContactStore](https://developer.apple.com/documentation/contacts/cncontactstore).
- (instancetype)initWithStore:(CNContactStore *)store {
    if (self = [super init]) {
        _store = store;
    }
    return self;
}


/// This method calls the Objective-C exclusive method `enumeratorForChangeHistoryFetchRequest`.
///
/// - Parameter request: A `CNChangeHistoryFetchRequest` object that describes the events to fetch.
/// - Parameter error: If the fetch fails, contains an `NSError` object with more information.
/// - Returns: A `CNFetchResult` object, which is returned by calling `enumeratorForChangeHistoryFetchRequest` on `CNContactStore`.
///
/// - Note: For more information, see [enumeratorForChangeHistoryFetchRequest](https://developer.apple.com/documentation/contacts/cncontactstore/enumeratorforchangehistoryfetchrequest:error:/)
///  and [CNFetchResult](https://developer.apple.com/documentation/contacts/cnfetchresult)
///
/// Example:
/// ```swift
/// let result = wrapper.changeHistoryFetchResult(fetchRequest, error: nil)
/// guard let enumerator = result.value as? NSEnumerator else {
///     throw ContactError.failedToCreateNSEnumeratorForChangeHistory
/// }
/// enumerator
///    .compactMap {
///        $0 as? CNChangeHistoryEvent
///    }
///    .forEach { event in
///        // Process each event
///    }
/// ```
- (CNFetchResult *)changeHistoryFetchResult:(CNChangeHistoryFetchRequest *)request
                                      error:(NSError *__autoreleasing  _Nullable * _Nullable)error {
    CNFetchResult *fetchResult = [self.store enumeratorForChangeHistoryFetchRequest:request error:error];
    return fetchResult;
}
@end
