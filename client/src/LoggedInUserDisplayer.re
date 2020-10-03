module QueryFragment = [%relay.fragment
  {|
  fragment LoggedInUserDisplayer_query on Query {
    loggedInUser {
      ...UserButton_user
    }
  }
|}
];

[@react.component]
let make = (~query) => {
  let query = QueryFragment.use(query);

  <UserButton user={query.loggedInUser.fragmentRefs} />;
};
