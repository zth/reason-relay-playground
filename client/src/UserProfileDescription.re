module UserFragment = [%relay.fragment
  {|
  fragment UserProfileDescription_user on User {
    description
  }
|}
];

[@react.component]
let make = (~user) => {
  let user = UserFragment.use(user);

  <div className="w-2/3 text-gray-700 inline-block">
    {switch (user.description) {
     | Some(desc) => desc->React.string
     | None => React.null
     }}
  </div>;
};
