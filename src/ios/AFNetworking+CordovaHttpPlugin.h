#import <AFNetworking/AFHTTPSessionManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface AFHTTPSessionManager (CordovaHttpPlugin)

/**
 Creates and runs an `NSURLSessionDataTask` with a multipart request using given HTTP method.

 @param HTTPMethod The HTTP method used to create the request.
 @param URLString The URL string used to create the request URL.
 @param parameters The parameters to be encoded according to the client request serializer.
 @param block A block that takes a single argument and appends data to the HTTP body. The block argument is an object adopting the `AFMultipartFormData` protocol.
 @param uploadProgress A block object to be executed when the upload progress is updated. Note this block is called on the session queue, not the main queue.
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: the data task, and the response object created by the client response serializer.
 @param failure A block object to be executed when the task finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the data task and the error describing the network or parsing error that occurred.

 @see -dataTaskWithRequest:uploadProgress:downloadProgress:completionHandler:
 */
- (nullable NSURLSessionDataTask *)uploadTaskWithHTTPMethod:(NSString *)HTTPMethod
                                                  URLString:(NSString *)URLString
                                                 parameters:(nullable id)parameters
                                  constructingBodyWithBlock:(nullable void (^)(id <AFMultipartFormData> formData))block
                                                   progress:(nullable void (^)(NSProgress *uploadProgress))uploadProgress
                                                    success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success
                                                    failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;

/**
 Creates and runs an `NSURLSessionDataTask` with given HTTP method.

 @param URLString The URL string used to create the request URL.
 @param parameters The parameters to be encoded according to the client request serializer.
 @param uploadProgress A block object to be executed when the upload progress is updated. Note this block is called on the session queue, not the main queue.
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: the data task, and the response object created by the client response serializer.
 @param failure A block object to be executed when the task finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the data task and the error describing the network or parsing error that occurred.

 @see -dataTaskWithRequest:uploadProgress:downloadProgress:completionHandler:
 */
- (nullable NSURLSessionDataTask *)uploadTaskWithHTTPMethod:(NSString *)HTTPMethod
                                                  URLString:(NSString *)URLString
                                                 parameters:(nullable id)parameters
                                                   progress:(nullable void (^)(NSProgress *uploadProgress))uploadProgress
                                                    success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success
                                                    failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;

/**
 Creates and runs an `NSURLSessionDataTask` with a given HTTP method.

 @param HTTPMethod The HTTP method used to create the request.
 @param URLString The URL string used to create the request URL.
 @param parameters The parameters to be encoded according to the client request serializer.
 @param downloadProgress A block object to be executed when the download progress is updated. Note this block is called on the session queue, not the main queue.
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: the data task, and the response object created by the client response serializer.
 @param failure A block object to be executed when the task finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the data task and the error describing the network or parsing error that occurred.

 @see -dataTaskWithRequest:uploadProgress:downloadProgress:completionHandler:
 */
- (nullable NSURLSessionDataTask *)downloadTaskWithHTTPMethod:(NSString *)HTTPMethod
                                                    URLString:(NSString *)URLString
                                                   parameters:(nullable id)parameters
                                                     progress:(nullable void (^)(NSProgress *downloadProgress))downloadProgress
                                                      success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success
                                                      failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;


- (nullable NSURLSessionDataTask *)dataTaskWithHTTPMethod:(NSString *)method
                                                URLString:(NSString *)URLString
                                               parameters:(id)parameters
                                           uploadProgress:(nullable void (^)(NSProgress *uploadProgress)) uploadProgress
                                         downloadProgress:(nullable void (^)(NSProgress *downloadProgress)) downloadProgress
                                                  success:(void (^)(NSURLSessionDataTask *, id))success
                                                  failure:(void (^)(NSURLSessionDataTask *, NSError *))failure;

@end

/**
`AFNetworkingOperationFailingURLResponseBodyErrorKey`
The corresponding value is an `NSString` containing the decoded error message.
 */

FOUNDATION_EXPORT NSString * const AFNetworkingOperationFailingURLResponseBodyErrorKey;

NS_ASSUME_NONNULL_END
