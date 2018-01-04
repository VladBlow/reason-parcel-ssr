let component = ReasonReact.statelessComponent("Nav");

let make = (_children) => {
  ...component,
  render: (_self) => <nav> <Link _to="/" name="Home" /> <Link _to="/about" name="About" /> </nav>
};