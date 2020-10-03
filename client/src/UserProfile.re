module Query = [%relay.query
  {|
  query UserProfileQuery($id: ID!) {
    node(id: $id) {
      __typename
      ... on User {
        id
        ...UserProfileHeader_user
        ...UserProfileDescription_user
        ...TasksForUser_user
      }
    }
  }
|}
];

[@react.component]
let make = (~preloadedUser) => {
  let data =
    Query.usePreloaded(~queryRef=preloadedUser, ~renderPolicy=Partial, ());

  switch (data.node) {
  | Some(user) =>
    <div className="text-center">
      <UserProfileHeader user={user.fragmentRefs} />
      <React.Suspense fallback={<div />}>
        <UserProfileDescription user={user.fragmentRefs} />
        <TasksForUser user={user.fragmentRefs} />
      </React.Suspense>
    </div>
  | None => React.string("404")
  };
};
