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

/// Initializes the wrapper with a specific `CNContactStore` instance.
///
/// - Parameter store: A `CNContactStore` instance to be used by this wrapper.
///
/// - Note: For more information, see [CNContactStore](https://developer.apple.com/documentation/contacts/cncontactstore).
- (instancetype)initWithStore:(CNContactStore *)store NS_DESIGNATED_INITIALIZER;


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
                                      error:(NSError *__autoreleasing  _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
