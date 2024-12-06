// swift-tools-version: 5.10.0
import PackageDescription

let package = Package(
    name: "CNContactStoreWrapper",
    platforms: [.macOS(.v10_15),
                .iOS(.v13),
                .watchOS(.v4)],
    products: [
        .library(
            name: "CNContactStoreWrapper",
            targets: ["CNContactStoreWrapper"]
        )
    ],
    targets: [
        .target(
            name: "CNContactStoreWrapper",
            path: "CNContactStoreWrapper",
            publicHeadersPath: ""
        )
    ]
)
