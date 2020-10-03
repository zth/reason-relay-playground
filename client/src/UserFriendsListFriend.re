module UserFragment = [%relay.fragment
  {|
  fragment UserFriendsListFriend_user on User {
    id
    name
    ...Avatar_user
  }
|}
];

[@react.component]
let make = (~user) => {
  let user = UserFragment.use(user);

  <div
    className="flex flex-row items-center p-4 ml-2 mt-2 bg-white shadow-lg w-48">
    <Avatar user={user.fragmentRefs} />
    <ReasonRelayRouter.Link to_={"/user/" ++ user.id}>
      <h3 className="ml-1 text-xl font-sans font-bold truncate">
        {React.string(user.name)}
      </h3>
    </ReasonRelayRouter.Link>
  </div>;
};
