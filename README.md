# CNContactStoreWrapper

CNContactStoreWrapper is a SPM library for interacting with `CNContactStore`.

## Motivation

To enumerate changes to the `CNContactStore` we must use the method [enumeratorForChangeHistoryFetchRequest](https://developer.apple.com/documentation/contacts/cnchangehistoryfetchrequest). This method is only exposed in Obj-C so we can wrap the store in an Obj-C class and expose the method to Swift.

## Installation

You can add CNContactStoreWrapper to an Xcode project by adding it as a package dependency.

> https://github.com/MultiScott/CNContactStoreWrapper

If you want to use CNContactStoreWrapper in a [SwiftPM](https://swift.org/package-manager/) project, it's as simple as adding it to a `dependencies` clause in your `Package.swift`:

``` swift
dependencies: [
  .package(url: "https://github.com/MultiScott/CNContactStoreWrapper", from: "0.1.0")
]
```


## Usage

```swift
import CNContactStoreWrapper
...

let wrapper = ContactStoreWrapper(store: store)
await withCheckedContinuation { continuation in
            DispatchQueue.global(qos: .userInitiated).async { [self] in
                let result = wrapper.changeHistoryFetchResult(fetchHistoryRequest, error: nil)
                // Saving the result's token as stated in CNContactStore documentation, ie:
                // https://developer.apple.com/documentation/contacts/cncontactstore/3113739-currenthistorytoken
                // When fetching contacts or change history events, use the token on CNFetchResult instead.
                savedToken = result.currentHistoryToken
                guard let enumerator = result.value as? NSEnumerator else { return }
                enumerator
                    .compactMap {
                        $0 as? CNChangeHistoryEvent
                    }
                    .forEach { event in
                        // The appropriate `visit(_:)` method will be called right away
                        event.accept(visitor)
                    }
                continuation.resume()
            }
        }
```

## License

[MIT](https://choosealicense.com/licenses/mit/)
