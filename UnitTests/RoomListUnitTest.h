#pragma once
#include"../Structures/RoomList.h"
#include"../Model/ReservedRoom.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include"../doctest.h"

// ���� �� ������� ���� �������. ���� ��� �� �� ������ ��������, ������ ��������� ���� �� ���� �
//��� �� ��� ������ ��-���� ������ � �� �� ������� ���� �� �������, �� ���� ���� � �����
/*

TEST_CASE("ADD-TO-LIST") {
	RoomList<ReservedRoom> l("test.test");
	int curSize = l.getDataSize();
	l.addToList(ReservedRoom());
	CHECK_EQ(l.getDataSize() - curSize, 1);
}

TEST_CASE("ADD-TO-LIST") {
	RoomList<ReservedRoom> l("test.test");
	int curSize = l.getDataSize();
	l.addToList(ReservedRoom());
	l.addToList(ReservedRoom());
	CHECK_EQ(l.getDataSize() - curSize, 1);
}

TEST_CASE("ADD-TO-LIST") {
	RoomList<ReservedRoom> l("test.test");
	ReservedRoom r(1, Interval());
	l.addToList(r);
	CHECK_EQ(r, l.getData()[l.getDataSize() - 1]);
}

TEST_CASE("IS-IN-LIST") {
	RoomList<ReservedRoom> l("test.test");
	ReservedRoom r(1, Interval());
	l.addToList(r);
	CHECK_EQ(l.isInList(r), true);
}

TEST_CASE("IS-IN-LIST") {
	RoomList<ReservedRoom> l("test.test");
	ReservedRoom r(1, Interval());
	l.addToList(r);
	CHECK_EQ(l.isInList(ReservedRoom()), false);
}

TEST_CASE("REMOVE-FROM-LIST") {
	RoomList<ReservedRoom> l("test.test");
	ReservedRoom r(1, Interval());
	l.addToList(r);
	l.removeFromList(r);
	CHECK_EQ(l.isInList(r), false);
}

TEST_CASE("REMOVE-FROM-LIST") {
	RoomList<ReservedRoom> l("test.test");
	int curSize = l.getDataSize();
	ReservedRoom r(1, Interval());
	l.addToList(r);
	l.removeFromList(r);
	CHECK_EQ(curSize, l.getDataSize());
}*/