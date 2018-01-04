[@bs.module "./utils/registerServiceWorker"] external registerServiceWorker : unit => unit =
  "default";

let history = History.createBrowserHistory();

AppShell.bootstrap() |> AppShell.render(history##location);

registerServiceWorker();