/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2015 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include <set>
#include <utility>

int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"

	Info << "Hello there, the most recent time folder found is " << runTime.timeName() << nl
		 << "The mesh has " << mesh.C().size() << " cells and " << mesh.Cf().size()
         << " internal faces in it. Wubalubadubdub!" << nl << endl;

    std::set<std::pair<label, label>> cellPairs;

    //writing set to file
    std::ofstream file;
    file.open("cellPairs.txt");
    
    for (int i = 0; i < mesh.C().size(); i++)
    {
        for (auto neigborsCells : mesh.cellCells()[i])
        {
            file << i << " " << neigborsCells << std::endl;
        }
    }
    file.close();

    return 0;
}


// ************************************************************************* //
