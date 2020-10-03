module Query = [%relay.query
  {|
  query ViewerProfileQuery {
    loggedInUser {
      ...UserProfileHeader_user
      ...UserProfileDescription_user
      ...UserFriendsList_user
    }
  }
|}
];

[@react.component]
let make = (~preloadedUser) => {
  let data =
    Query.usePreloaded(~queryRef=preloadedUser, ~renderPolicy=Partial, ());

  <div className="text-center">
    <UserProfileHeader user={data.loggedInUser.fragmentRefs} />
    <React.Suspense fallback={<ContentLoader.Facebook />}>
      <UserProfileDescription user={data.loggedInUser.fragmentRefs} />
      <UserFriendsList user={data.loggedInUser.fragmentRefs} />
    </React.Suspense>
  </div>;
};
