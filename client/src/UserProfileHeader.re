module UserFragment = [%relay.fragment
  {|
  fragment UserProfileHeader_user on User {
    ...Avatar_user
    name
  }
|}
];

[@react.component]
let make = (~user) => {
  let user = UserFragment.use(user);

  <div className="text-center">
    <Avatar user={user.fragmentRefs} size=`large />
    <h1 className="font-sans text-4xl font-bold text-center">
      {React.string(user.name)}
    </h1>
  </div>;
};
