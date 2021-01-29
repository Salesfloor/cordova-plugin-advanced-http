#import <Foundation/Foundation.h>
#import <AFNetworking/AFURLRequestSerialization.h>

@interface BinaryRequestSerializer : AFHTTPRequestSerializer

+ (instancetype)serializer;

@end
