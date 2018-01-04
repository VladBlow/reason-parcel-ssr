let component = ReasonReact.statelessComponent("About");

let make = (~redirect, _children) => {
  ...component,
  render: (_self) =>
    <div>
      <ReactHelmet>
        <title> (Utils.text("About ReasonReact Starter")) </title>
        <meta name="description" content="About page description" />
      </ReactHelmet>
      <a onClick=(redirect("/"))> ("Home" |> Utils.text) </a>
      <a onClick=(redirect("/about"))> ("About" |> Utils.text) </a>
      <Hello message="Hola from about component" />
    </div>
};