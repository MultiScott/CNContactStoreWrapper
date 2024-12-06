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

/// A wrapper for the `CNContactStore` class, providing additional functionality for
/// interacting with the Contacts framework.
///
/// This exposes Obj-C `CNContactStore` API by providing
/// helpera  method to  fetching change history events. Designed to bridge
/// Objective-C and Swift interoperability, `CNContactStoreWrapper` can be used
/// seamlessly in mixed-language projects.
///
/// - Note: For more details on the Contacts framework, refer to the [Apple Documentation](https://developer.apple.com/documentation/contacts).
@interface CNContactStoreWrapper : NSObject

- (instancetype)initWithStore:(CNContactStore *)store NS_DESIGNATED_INITIALIZER;

- (CNFetchResult *)changeHistoryFetchResult:(CNChangeHistoryFetchRequest *)request
                                      error:(NSError *__autoreleasing  _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
