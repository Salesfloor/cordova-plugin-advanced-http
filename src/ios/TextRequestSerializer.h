#import <Foundation/Foundation.h>
#import <AFNetworking/AFURLRequestSerialization.h>

@interface TextRequestSerializer : AFHTTPRequestSerializer

+ (instancetype)serializer;

@end
