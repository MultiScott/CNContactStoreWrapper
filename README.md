# CNContactStoreWrapper

CNContactStoreWrapper is a SPM library for interacting with `CNContactStore`.

## Motivation

To enumerate changes to the `CNContactStore` we must use the method [enumeratorForChangeHistoryFetchRequest](https://developer.apple.com/documentation/contacts/cnchangehistoryfetchrequest). This method is only exposed in Obj-C so we can wrap the store in an Obj-C class and expose the result to Swift.

## Installation

You can add CNContactStoreWrapper to an Xcode project by adding it as a package dependency.

> https://github.com/MultiScott/CNContactStoreWrapper

If you want to use CNContactStoreWrapper in a [SwiftPM](https://swift.org/package-manager/) project, it's as simple as adding it to a `dependencies` clause in your `Package.swift`:

``` swift
dependencies: [
  .package(url: "https://github.com/MultiScott/CNContactStoreWrapper", from: "0.2.0")
]
```


## Usage

```swift
import CNContactStoreWrapper

... 

let fetchRequest = CNChangeHistoryFetchRequest()
fetchRequest.startingToken = self.currentHistoryToken
fetchRequest.shouldUnifyResults = true
let wrapper = CNContactStoreWrapper(store: contactStore)
let result = wrapper.changeHistoryFetchResult(fetchRequest, error: nil)
guard let enumerator = result.value as? NSEnumerator else {
    throw ContactError.failedToCreateNSEnumeratorForChangeHistory
}
enumerator
    .compactMap {
        $0 as? CNChangeHistoryEvent
    }
    .forEach { event in
        switch event {
        case let addContactEvent as CNChangeHistoryAddContactEvent:
            print("Added Contact: \(addContactEvent.contact.identifier)")
            // Handle adding to your local store
            
        case let updateContactEvent as CNChangeHistoryUpdateContactEvent:
            print("Updated Contact: \(updateContactEvent.contact.identifier)")
            // Handle updating in your local store
            
        case let deleteContactEvent as CNChangeHistoryDeleteContactEvent:
            print("Deleted Contact with ID: \(deleteContactEvent.contactIdentifier)")
            // Handle deletion in your local store
            
        case let addGroupEvent as CNChangeHistoryAddGroupEvent:
            print("Added Group: \(addGroupEvent.group.identifier)")
            // Handle group addition if needed
            
        case let updateGroupEvent as CNChangeHistoryUpdateGroupEvent:
            print("Updated Group: \(updateGroupEvent.group.identifier)")
            // Handle group updates if needed
            
        case let deleteGroupEvent as CNChangeHistoryDeleteGroupEvent:
            print("Deleted Group with ID: \(deleteGroupEvent.groupIdentifier)")
            // Handle group deletion if needed
            
        case let addMemberEvent as CNChangeHistoryAddMemberToGroupEvent:
            print("Added member \(addMemberEvent.member.identifier) to group \(addMemberEvent.group.identifier)")
            // Handle member addition
            
        case let removeMemberEvent as CNChangeHistoryRemoveMemberFromGroupEvent:
            print("Removed member \(removeMemberEvent.member.identifier) from group \(removeMemberEvent.group.identifier)")
            // Handle member removal
            
        default:
            break
        }
    }
```

## Attribution

This solution was inspired and informed by this [StackOverFlow post](https://stackoverflow.com/questions/73861250/how-would-i-check-if-a-cncontact-has-changed-since-the-last-time-my-ios-app-save/75860924#75860924) answered by [andercover](https://stackoverflow.com/users/1425697/andercover).

## License

[MIT](https://choosealicense.com/licenses/mit/)
