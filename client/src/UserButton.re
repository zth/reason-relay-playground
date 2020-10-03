module UserFragment = [%relay.fragment
  {|
  fragment UserButton_user on User {
    name
    id
    isLoggedInUser
    ...Avatar_user
  }
|}
];

[@react.component]
let make = (~user) => {
  let user = UserFragment.use(user);
  let name = user.name;

  <ReasonRelayRouter.Link
    to_={"/user/" ++ (user.isLoggedInUser ? "me" : user.id)}
    className="flex items-center focus:outline-none mr-3">
    <Avatar user={user.fragmentRefs} />
    <span className="hidden md:inline-block ml-2">
      {j|Hi, $name|j}->React.string
    </span>
  </ReasonRelayRouter.Link>;
};
