type size =
  | Half
  | OneThird;

let sizeToClassName =
  fun
  | Half => " md:w-1/2 "
  | OneThird => " md:w-1/2 xl:w-1/3 ";

[@react.component]
let make = (~title, ~size) => {
  <div className={"w-full p-3" ++ size->sizeToClassName}>
    <div className="bg-white border rounded shadow">
      <div className="border-b p-3">
        <h5 className="font-bold uppercase text-gray-600">
          {React.string(title)}
        </h5>
      </div>
      <div className="p-5">
        <canvas
          id="chartjs-7"
          className="chartjs"
          width="undefined"
          height="undefined"
        />
      </div>
    </div>
  </div>;
};
