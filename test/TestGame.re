open Framework;
open TennisKata.Game;

describe("Test Game transitions", ({test}) => 
{
    test("Given PlayerOne then PlayerTwo is different", ({expect}) => {
    expect.notEqual(PlayerOne, PlayerTwo);
    });

    test("Given advantage when advantaged player wins then score is correct",
        ({expect}) => {
            let advantagedPlayer = PlayerOne;
            let winner = advantagedPlayer;
            expect.equal(
                    scoreWhenAdvantage(advantagedPlayer, winner),
                    Game(advantagedPlayer),
            );
    });

    test("Given advantage when the other player wins then score is Deuce",
        ({expect}) => {
            let advantagedPlayer = PlayerOne;
            let winner = other(advantagedPlayer);
                expect.equal(
                scoreWhenAdvantage(advantagedPlayer, winner),
                Deuce,
                );
    });

    test("Given player: 40 when wins then score is Game for this player",
        ({expect}) => {
            let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
            expect.equal(
                    scoreWhenForty(fortyThirty, fortyThirty.player),
                    Game(fortyThirty.player),
            );
    });

    test("Given player: 40 | other : 30 when other wins then score is Deuce",
        ({expect}) => {
            let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
            expect.equal(
                    scoreWhenForty(fortyThirty, other(fortyThirty.player)),
                    Deuce
            );
    });

    test("Given player: 40 | other : 0 when other wins then score is fortyFifteen",
        ({expect}) => {
            let fortyLove = {player: PlayerOne, otherPlayerPoint: Love};
            let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
            expect.equal(
                    scoreWhenForty(fortyLove, other(fortyLove.player)),
                    Forty(fortyFifteen)
            );
    });

    test("Given player: 15 | other : 15 when player wins then score is 30/15",
        ({expect}) => {
            let fifteenFifteen = {playerOne: Fifteen, playerTwo: Fifteen};
            let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
            expect.equal(
                    scoreWhenPoints(fifteenFifteen, PlayerOne),
                    Points(thirtyFifteen)
            );
    });

    test("Given player: 0 | other : 15 when other wins then score is 0/30",
        ({expect}) => {
             let loveFifteen = {playerOne: Love, playerTwo: Fifteen};
             let loveThirty = {playerOne: Love, playerTwo: Thirty};
             expect.equal(
                   scoreWhenPoints(loveFifteen, PlayerTwo),
                   Points(loveThirty)
             );
    });

    test("Given player: 30 | other : 15 when player wins then score is 40/15",
        ({expect}) => {
              let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
              let fortyFifteen = Forty({player: PlayerOne, otherPlayerPoint: Fifteen});
              expect.equal(
                    scoreWhenPoints(thirtyFifteen, PlayerOne),
                    fortyFifteen
                  );
    });

    test("string_to_player when (player one) then echo 'Player One'",
          ({expect}) => {
            expect.equal(
                    string_of_player(PlayerOne),
                    "Player One"
            );
          });

    test("string_to_player when (player Two) then echo 'Player Two'",
              ({expect}) => {
                expect.equal(
                        string_of_player(PlayerTwo),
                    "Player Two"
                );
              });

    test("string_of_point when player point is Love",
                 ({expect}) => {
                   expect.equal(
                     string_of_point(Love),
                     "0"
                   );
           });

    test("string_of_point when player point is Fifteen",
                 ({expect}) => {
                   expect.equal(
                     string_of_point(Fifteen),
                     "15"
                   );
           });

    test("string_of_point when player point is thirty",
                 ({expect}) => {
                   expect.equal(
                     string_of_point(Thirty),
                     "30"
                   );
           });

    test("string_of_point when player point is Forty",
                  ({expect}) => {
                    expect.equal(
                      string_of_point(Forty),
                      "40"
                    );
           });

    test("string_of_score when it is Points",
        ({expect}) => {
          let pointsPlayers = {playerOne: Love, playerTwo: Thirty};
          expect.equal(
            string_of_score(Points(pointsPlayers)),
            "( Player One == 0 ) | ( Player Two == 30 )"
          );
      });

      test("string_of_score when it is Forty",
        ({expect}) => {
          let fortyData = { {player: PlayerOne, otherPlayerPoint:Thirty} } ;
          expect.equal(
            string_of_score(Forty(fortyData)),
            "( Player One == 40 ) | (Player Two == 30 )"
          );
      });

      test("string_of_score when it is Deuce",
        ({expect}) => {
          expect.equal(
            string_of_score(Deuce),
            "Equality 40"
          );
      });

      test("string_of_score when it is Advantage",
        ({expect}) => {
        let advantagePlayer = PlayerOne;
          expect.equal(
            string_of_score(Advantage(advantagePlayer)),
            "Advantage to Player One"
          );
      });

      test("string_of_score when its annonced the winner of the game",
        ({expect}) => {
        let winnerPlayer = PlayerOne;
          expect.equal(
            string_of_score(Advantage(winnerPlayer)),
            "Advantage to Player One"
          );
      });
});




