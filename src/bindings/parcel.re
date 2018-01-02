type t;

[@bs.module] [@bs.new]
external bundler : string => Express.Middleware.t = "parcel-bundler";

[@bs.send.pipe : 't]
external middleware : unit => Express.Middleware.t = "middleware";