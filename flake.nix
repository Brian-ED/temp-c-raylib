{
  description = "temp-c-raylib for raylib-apl";

  inputs = {
    flake-utils.url = "github:numtide/flake-utils";
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };
  outputs = { self, nixpkgs, flake-utils }: let
    systems = [ "x86_64-linux" "aarch64-linux" "x86_64-darwin" ];
  in flake-utils.lib.eachSystem systems (system:
    let
      pkgs = nixpkgs.legacyPackages.${system};
      callPackage = pkgs.lib.callPackageWith (pkgs // packages);
      packages = {
        default = callPackage ./default.nix {};
      };
    in {
      inherit packages;
    }
  );
}
