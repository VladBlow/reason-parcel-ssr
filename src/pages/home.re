let component = ReasonReact.statelessComponent("Home");

let make = (~redirect, _children) => {
  ...component,
  render: (_self) =>
    <div>
      <ReactHelmet>
        <title> (Utils.text("ReasonReact Starter")) </title>
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
      </ReactHelmet>
      <a onClick=(redirect("/"))> ("Home" |> Utils.text) </a>
      <a onClick=(redirect("/about"))> ("About" |> Utils.text) </a>
      <Hello message="Hello from home component" />
      <Box _as="p"> ("Testing 1, 2" |> Utils.text) </Box>
    </div>
};