#import <Foundation/Foundation.h>
#import <AFNetworking/AFURLResponseSerialization.h>

@interface BinaryResponseSerializer : AFHTTPResponseSerializer

+ (instancetype)serializer;

@end
