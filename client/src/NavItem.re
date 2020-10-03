[@react.component]
let make = (~title, ~to_) => {
  <li className="mr-6 my-2 md:my-0">
    <ReasonRelayRouter.Link
      to_
      className="block py-1 md:py-3 pl-1 align-middle no-underline hover:text-gray-900 ">
      <i className="fas fa-home fa-fw mr-3 text-orange-600" />
      <span className="pb-1 md:pb-0 text-sm"> {React.string(title)} </span>
    </ReasonRelayRouter.Link>
  </li>;
};
