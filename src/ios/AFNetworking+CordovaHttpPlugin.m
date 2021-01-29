#import "AFNetworking+CordovaHttpPlugin.h"

@implementation AFHTTPSessionManager (CordovaHttpPlugin)

- (NSURLSessionDataTask *)uploadTaskWithHTTPMethod:(NSString *)method
                                         URLString:(NSString *)URLString
                                        parameters:(id)parameters
                         constructingBodyWithBlock:(void (^)(id <AFMultipartFormData> formData))block
                                          progress:(nullable void (^)(NSProgress * _Nonnull))uploadProgress
                                           success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
                                           failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure
{
    NSError *serializationError = nil;
    NSMutableURLRequest *request = [self.requestSerializer multipartFormRequestWithMethod:method URLString:[[NSURL URLWithString:URLString relativeToURL:self.baseURL] absoluteString] parameters:parameters constructingBodyWithBlock:block error:&serializationError];
    [request setHTTPShouldHandleCookies:NO];

    if (serializationError) {
        if (failure) {
            dispatch_async(self.completionQueue ?: dispatch_get_main_queue(), ^{
                failure(nil, serializationError);
            });
        }

        return nil;
    }

    __block NSURLSessionDataTask *task = [self uploadTaskWithStreamedRequest:request progress:uploadProgress completionHandler:^(NSURLResponse * __unused response, id responseObject, NSError *error) {
        if (error) {
            if (failure) {
                failure(task, error);
            }
        } else {
            if (success) {
                success(task, responseObject);
            }
        }
    }];

    [task resume];

    return task;
}

- (NSURLSessionDataTask *)uploadTaskWithHTTPMethod:(NSString *)method
                                         URLString:(NSString *)URLString
                                        parameters:(id)parameters
                                          progress:(void (^)(NSProgress * _Nonnull))uploadProgress
                                           success:(void (^)(NSURLSessionDataTask * _Nonnull, id _Nullable))success
                                           failure:(void (^)(NSURLSessionDataTask * _Nullable, NSError * _Nonnull))failure
{
    NSURLSessionDataTask *dataTask = [self dataTaskWithHTTPMethod:method URLString:URLString parameters:parameters uploadProgress:uploadProgress downloadProgress:nil success:success failure:failure];

    [dataTask resume];

    return dataTask;
}

- (NSURLSessionDataTask *)downloadTaskWithHTTPMethod:(NSString *)method
                                           URLString:(NSString *)URLString
                                          parameters:(id)parameters
                                            progress:(nullable void (^)(NSProgress * _Nonnull))downloadProgress
                                             success:(void (^)(NSURLSessionDataTask * _Nonnull, id _Nullable))success
                                             failure:(void (^)(NSURLSessionDataTask * _Nullable, NSError * _Nonnull))failure
{
    NSURLSessionDataTask *task = [self dataTaskWithHTTPMethod:method URLString:URLString parameters:parameters uploadProgress:nil downloadProgress:downloadProgress success:success failure:failure];

    [task resume];

    return task;
}

@end

NSString * const AFNetworkingOperationFailingURLResponseBodyErrorKey = @"com.alamofire.serialization.response.error.body";
