//
//  MPAdServerURLBuilder.h
//
//  Copyright 2018-2021 Twitter, Inc.
//  Licensed under the MoPub SDK License Agreement
//  http://www.mopub.com/legal/sdk-license-agreement/
//

#import <Foundation/Foundation.h>
#import "MPAdTargeting.h"
#import "MPURL.h"

@interface MPAdServerURLBuilder : NSObject

/**
 Name of the engine using the MoPub SDK. This field is @c nil for platform native integrations.
 */
@property (class, nonatomic, copy) NSString *engineName;

/**
 Version of the engine using the MoPub SDK. This field is @c nil for platform native integrations.
 */
@property (class, nonatomic, copy) NSString *engineVersion;

/**
 Returns an NSURL object given NSURLComponents and a dictionary of query parameters/values
 */
+ (MPURL *)URLWithComponents:(NSURLComponents *)components postData:(NSDictionary *)parameters;

@end

@interface MPAdServerURLBuilder (Ad)

+ (MPURL *)URLWithAdUnitID:(NSString *)adUnitID
                 targeting:(MPAdTargeting *)targeting;

+ (MPURL *)URLWithAdUnitID:(NSString *)adUnitID
                 targeting:(MPAdTargeting *)targeting
             desiredAssets:(NSArray *)assets;

+ (MPURL *)URLWithAdUnitID:(NSString *)adUnitID
                 targeting:(MPAdTargeting *)targeting
             desiredAssets:(NSArray *)assets
                adSequence:(NSInteger)adSequence;

@end

@interface MPAdServerURLBuilder (Open)

/**
 Constructs the conversion tracking URL using current consent state, SDK state, and @c appID parameter.
 @param appID The App ID to be included in the URL.
 @returns URL to the open endpoint configuring for conversion tracking.
 */
+ (MPURL *)conversionTrackingURLForAppID:(NSString *)appID;

/**
 Constructs the session tracking URL using current consent state and SDK state.
 @returns URL to the open endpoint configuring for session tracking.
 */
+ (MPURL *)sessionTrackingURL;

@end

@interface MPAdServerURLBuilder (Consent)

/**
 Constructs the consent synchronization endpoint URL using the current consent manager
 state.
 @returns URL to the consent synchronization endpoint.
 */
+ (MPURL *)consentSynchronizationUrl;

/**
 Constructs the URL to fetch the consent dialog using the current consent manager state.
 @returns URL to the consent dialog endpoint
 */
+ (MPURL *)consentDialogURL;

@end

@interface MPAdServerURLBuilder (Native)

/**
 Constructs the URL to fetch the native ad positions for the given ad unit ID.
 @param adUnitId Native ad unit ID to fetch positioning information.
 @return URL for the native position request if successful; otherwise @c nil.
 */
+ (MPURL *)nativePositionUrlForAdUnitId:(NSString *)adUnitId;

@end

@interface MPAdServerURLBuilder (Rewarded)

/**
 Appends additional reward information to the source rewarded completion.
 @param sourceUrl The source rewarded completion URL given by the server.
 @param customerId Optional customer ID to associate with the reward.
 @param rewardType Optional reward type to associate with the customer.
 Both @c rewardType and @c rewardAmount must be present in order for them to be added.
 @param rewardAmount Optional reward amount to associate with the reward type.
 Both @c rewardType and @c rewardAmount must be present in order for them to be added.
 @param adapterClassName Optional name of the adapter class used to render the rewarded ad.
 @param additionalData Optional additional data passed in by the publisher to be sent back to
 their reward server.
 @return Expanded URL if successful; otherwise @c nil.
 */
+ (MPURL *)rewardedCompletionUrl:(NSString *)sourceUrl
                  withCustomerId:(NSString *)customerId
                      rewardType:(NSString *)rewardType
                    rewardAmount:(NSNumber *)rewardAmount
                adapterClassName:(NSString *)adapterClassName
                  additionalData:(NSString *)additionalData;

@end

@interface MPAdServerURLBuilder (SKAdNetwork)

/**
 Constructs URL to synchronize enabled SKAdNetwork networks with ad server.
 @param skAdNetworkIds List of SKAdNetwork IDs enabled for this app. Must be nonnull, more than one network
 @return URL to synchronize SKAdNetwork IDs to ad server, or @c nil if requirements for @c skAdNetworkIds are not met
 */
+ (MPURL *)skAdNetworkSynchronizationURLWithSkAdNetworkIds:(NSArray <NSString *> *)skAdNetworkIds;

@end
