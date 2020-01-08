#include "MovePieceCommand.hpp"

MovePieceCommand::MovePieceCommand(Board& board, Position const& origin, Position const& destination) : board_(board), origin_(origin), destination_(destination)
{
	pieceMoved_ = board_.GetPieceAtPosition(origin_);
	pieceCaptured_ = board_.GetPieceAtPosition(destination_);
	wasPieceCaptured_ = pieceCaptured_ == nullptr ? false : true;
}

void MovePieceCommand::execute()
{
	//TODO remove the cpatured piece if there is one
	if (pieceCaptured_ != nullptr)
	{
		board_.pieces.remove(pieceCaptured_);
	}

	//move piece
	pieceMoved_->MoveToLocation(destination_);
	board_.board[destination_.y][destination_.x] = pieceMoved_->GetRank();
	board_.notify(Event::INPUT_VIEW);

	//change players turn
	board_.isWhitePlayersTurn = !board_.isWhitePlayersTurn;
}

void MovePieceCommand::undo()
{
	//TODO undo behaviour

	//lastly, set the pointer back to null so we don't delete the piece twice
	pieceCaptured_ = nullptr;
}

MovePieceCommand::~MovePieceCommand()
{
	if (pieceCaptured_ != nullptr)
		delete pieceCaptured_;
}